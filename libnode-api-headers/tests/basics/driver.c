#include <stddef.h>
#include <stdint.h>

#include <node_api.h>

#undef NDEBUG
#include <assert.h>

/* Define the module initializer and the API version query with the
 * registration macros, the same way an addon does. Neither refers to the
 * functions that the host process provides, so we can call both directly.
 */
NAPI_MODULE_INIT ()
{
  (void) env;
  return exports;
}

int main ()
{
  /* Default API version.
   */
  assert (NAPI_VERSION == 8);
  assert (NODE_API_MODULE_GET_API_VERSION () == NAPI_VERSION);

  /* Module initializer.
   */
  {
    int x;
    napi_value e = (napi_value) &x;
    assert (NAPI_MODULE_INITIALIZER ((napi_env) 0, e) == e);
  }

  /* Types and constants.
   */
  assert (napi_ok == 0);
  assert (NAPI_AUTO_LENGTH == SIZE_MAX);
  assert (sizeof (napi_value) == sizeof (void*));
  assert ((napi_default_jsproperty & napi_writable) != 0);

  return 0;
}
