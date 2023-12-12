#include <iostream>
#include <mercury.h>

static hg_class_t*     hg_class   = NULL; /* the mercury class */
static hg_context_t*   hg_context = NULL; /* the mercury context */

int main(int argc, char **argv) {
    hg_return_t ret;

    hg_class = HG_Init("verbs", HG_TRUE);
    assert (hg_class != NULL);

    char hostname[128];
    hg_addr_t self_addr;
    HG_Addr_self(hg_class, &self_addr);
    HG_Addr_to_string(hg_class, hostname, &self_addr);
    printf("Server running at address %s\n",hostname);
    HG_Addr_free(hg_class, self_addr);

    hg_context = HG_Context_create(hg_class);
    assert(hg_context != NULL);

    ret = HG_Context_destroy(hg_context);
    assert(ret == HG_SUCCESS);

    ret = HG_Finalize(hg_class);
    assert(ret == HG_SUCCESS);

    return 0;
}