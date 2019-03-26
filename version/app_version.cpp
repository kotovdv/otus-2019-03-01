#include "app_version.h"
#include "current_version.h"
#include <string>

using std::string;

string getOrDefault(const string& value, const string& defaultValue) {
    return !value.empty()
           ? value
           : defaultValue;
}

string majorVersion() {
    return getOrDefault(PROJECT_VERSION_MAJOR, DEFAULT_VERSION_VALUE);
}

string minorVersion() {
    return getOrDefault(PROJECT_VERSION_MINOR, DEFAULT_VERSION_VALUE);
}

string patchVersion() {
    return getOrDefault(PROJECT_VERSION_PATCH, DEFAULT_VERSION_VALUE);
}

string applicationVersion() {
    return majorVersion() + "." + minorVersion() + "." + patchVersion();
}