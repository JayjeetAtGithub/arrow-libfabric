#include <iostream>

#include <rdma/fabric.h>
#include <rdma/fi_domain.h>
#include <rdma/fi_endpoint.h>
#include <rdma/fi_cm.h>
#include <rdma/fi_tagged.h>
#include <rdma/fi_rma.h>
#include <rdma/fi_errno.h>

int main() {
    std::cout << "Hello, world!" << std::endl;

    struct fi_info *hints, *fi;
    hints = fi_allocinfo();
    hints->ep_attr->type = FI_RDM;
    hints->caps = FI_MSG | FI_TAGGED | FI_RMA;
    hints->mode = FI_CONTEXT;
    hints->fabric_attr->prov_name = strdup(“psm2”);
    err = fi_getinfo(FI_VERSION(1,0), NULL, NULL, 0, hints, &fi);

    if (!err) {
        // traverse the fi_info linked list and print out the
        // information for each fabric interface
        for (fi_info *cur_fi = fi; cur_fi; cur_fi = cur_fi->next) {
            std::cout << "Fabric interface: " << cur_fi->fabric_attr->prov_name << std::endl;
        }
    }
}