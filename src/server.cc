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

    struct fi_info *fi;
    int err = fi_getinfo(FI_VERSION(1,0), NULL, NULL, 0, NULL, &fi);
    if (!err) {
        // traverse the fi_info linked list and print out the names of the providers
        for (struct fi_info *cur_fi = fi; cur_fi != NULL; cur_fi = cur_fi->next) {
            std::cout << cur_fi->fabric_attr->prov_name << std::endl;
        }
    }
}