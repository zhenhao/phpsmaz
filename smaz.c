/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_smaz.h"

/* If you declare any globals in php_smaz.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(smaz)
*/

/* True global resources - no need for thread safety here */
static int le_smaz;

/* {{{ smaz_functions[]
 *
 * Every user visible function must have an entry in smaz_functions[].
 */
const zend_function_entry smaz_functions[] = {
    PHP_FE(smaz_encode, NULL)
    PHP_FE(smaz_decode, NULL)
    PHP_FE_END    /* Must be the last line in smaz_functions[] */
};
/* }}} */

/* {{{ smaz_module_entry
 */
zend_module_entry smaz_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "smaz",
    smaz_functions,
    PHP_MINIT(smaz),
    PHP_MSHUTDOWN(smaz),
    PHP_RINIT(smaz),        /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(smaz),    /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(smaz),
#if ZEND_MODULE_API_NO >= 20010901
    "0.1", /* Replace with version number for your extension */
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SMAZ
ZEND_GET_MODULE(smaz)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("smaz.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_smaz_globals, smaz_globals)
    STD_PHP_INI_ENTRY("smaz.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_smaz_globals, smaz_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_smaz_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_smaz_init_globals(zend_smaz_globals *smaz_globals)
{
    smaz_globals->global_value = 0;
    smaz_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(smaz)
{
    /* If you have INI entries, uncomment these lines 
    REGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(smaz)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(smaz)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(smaz)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(smaz)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "smaz support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
PHP_FUNCTION(smaz_encode)
{
    char *arg = NULL;
    int arg_len, len;
    char strg[4096];

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
        return;
    }
    len = smaz_compress(arg, arg_len, strg, sizeof(strg));
    RETURN_STRINGL(strg, len, 1);
}

PHP_FUNCTION(smaz_decode)
{
    char *arg = NULL;
    int arg_len, len;
    char strg[4096];

    if(zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
        return;
    }
    
    len = smaz_decompress(arg, arg_len, strg, sizeof(strg));
    RETURN_STRINGL(strg, len, 1);
}

/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
