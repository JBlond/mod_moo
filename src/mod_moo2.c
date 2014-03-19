/* To install:
 *
 * apxs -cia mod_moo2.c
 *
 * Note that apxs might be called something else on your system if you
 * are Debian-encumbered.
 * 
 * Configure with:
 *
 * LoadModule moo2_module        modules/mod_moo2.so
 * <Location /moo>
 *   SetHandler moo
 * </Location>
 *
 * You can apparently configure this in a .htaccess file (not sure why
 * you'd want to) by creating a file named moo (it's fine if it's
 * empty) then putting this in your .htaccess file:
 *
 * <Files moo>
 * SetHandler moo
 * </Files>
 *
 * This module is licensed under the HJTI license 
 * (http://drbacchus.com/hjti) which is 100% compatible with 
 * the Apache Software License.
 *
 * This module is just mod_pony modified for Mario's moo cow.
 *
 */

#include <httpd.h>
#include <http_protocol.h>
#include <http_config.h>
#include <http_log.h>
#include <stdlib.h>

typedef struct {
    int mooprob;
} moo_config_rec;

module AP_MODULE_DECLARE_DATA moo2_module;

static int moo_handler(request_rec* r) {
    /* for mod_moo, none of this junk is really needed */
    int moorand = (int) (rand());
    moo_config_rec *conf = ap_get_module_config(r->per_dir_config,
                                                       &moo2_module);
    if ( !r->handler || strcmp(r->handler, "moo") ) {
        return DECLINED ;
    }
    if ( r->method_number != M_GET ) {
        return HTTP_METHOD_NOT_ALLOWED ;
    }

    /* Beging the truly needed stuff */
    ap_set_content_type(r, "text/html;charset=ascii") ;
//  	ap_rputs("<html><head><title>Have you mooed today?</title></head>\n", r);
   	ap_rputs("<pre>\n", r);
//ap_rputs("                              \n", r);
ap_rputs("         (__)                 \n", r);
ap_rputs("         (oo)                 \n", r); 
ap_rputs("   /------\\/                  \n", r); 
ap_rputs("  / |    ||                   \n", r); 
ap_rputs(" *  /\\---/\\                   \n", r); 
ap_rputs("    ~~   ~~                   \n", r); 
ap_rputs("....\"Have you mooed today?\"....\n", r); 
//ap_rputs("        <font color=\"#444444\" size=\"-1\">Powered by moo</font>\n", r); 
   	ap_rputs("</pre>\n", r);
//   	ap_rputs("</pre></body></html>\n", r);

    return OK ;
}

static int moo_init_handler(apr_pool_t *p, apr_pool_t *plog, apr_pool_t *ptemp,
                             server_rec *s)
{
    ap_add_version_component(p, "moo!/2.0");

    return OK;
}

static void moo_hooks(apr_pool_t* pool) {
    ap_hook_handler(moo_handler, NULL, NULL, APR_HOOK_MIDDLE);
    ap_hook_post_config(moo_init_handler, NULL, NULL, APR_HOOK_MIDDLE);
}

/* not needed for proper mooing! */
static void *create_moo_dir_config(apr_pool_t *p, char *d)
{
    moo_config_rec *conf = apr_palloc(p, sizeof(*conf));

    conf->mooprob = (int) RAND_MAX / 2;
    return conf;
}

module AP_MODULE_DECLARE_DATA moo2_module = {
        STANDARD20_MODULE_STUFF,
        create_moo_dir_config, /* not really needed to moo */
        NULL,
        NULL,
        NULL,
        NULL,
        moo_hooks
};

/*

del *.obj *.exp *.lib *.so *.*.man*
SET APACHE=\Apache24
cl /nologo /MD /W3 /O2 /D _WINDOWS /D WIN32 /D NDEBUG -I%APACHE%\include mod_moo2.c
link kernel32.lib "%APACHE%\lib\libhttpd.lib" "%APACHE%\lib\libapr-1.lib" "%APACHE%\lib\libaprutil-1.lib" /nologo /subsystem:windows /dll /out:mod_moo2.so mod_moo2.obj
MT -manifest mod_moo2.so.manifest  -outputresource:mod_moo2.so;2 

SET APACHE=\Apache24x64
cl /nologo /MD /W3 /O2 /D _WINDOWS /D WIN32 /D WIN64 /D _WIN64 /D NDEBUG -I%APACHE%\include mod_moo2.c
link kernel32.lib "%APACHE%\lib\libhttpd.lib" "%APACHE%\lib\libapr-1.lib" "%APACHE%\lib\libaprutil-1.lib" /nologo /subsystem:windows /dll /out:mod_moo2.so mod_moo2.obj
MT -manifest mod_moo2.so.manifest  -outputresource:mod_moo2.so;2 

*/