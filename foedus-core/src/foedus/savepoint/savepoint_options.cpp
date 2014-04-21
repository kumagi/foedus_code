/*
 * Copyright (c) 2014, Hewlett-Packard Development Company, LP.
 * The license and distribution terms for this file are placed in LICENSE.txt.
 */
#include <foedus/externalize/externalizable.hpp>
#include <foedus/savepoint/savepoint_options.hpp>
#include <string>
namespace foedus {
namespace savepoint {
SavepointOptions::SavepointOptions() {
    savepoint_path_ = "savepoint.xml";
}
ErrorStack SavepointOptions::load(tinyxml2::XMLElement* element) {
    EXTERNALIZE_LOAD_ELEMENT(element, savepoint_path_);
    return RET_OK;
}

ErrorStack SavepointOptions::save(tinyxml2::XMLElement* element) const {
    CHECK_ERROR(insert_comment(element, "Set of options for savepoint manager"));
    EXTERNALIZE_SAVE_ELEMENT(element, savepoint_path_, "Full path of the savepoint file.");
    return RET_OK;
}

}  // namespace savepoint
}  // namespace foedus