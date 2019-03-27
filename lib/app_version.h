#include <string>

using std::string;

#define DEFAULT_VERSION_VALUE "undefined"

/*
 * @return MAJOR version of application or DEFAULT_VERSION_VALUE if undefined
 */
string majorVersion();

/*
 * @return MINOR version of application or DEFAULT_VERSION_VALUE if undefined
 */
string minorVersion();

/*
 * @return PATCH version of application or DEFAULT_VERSION_VALUE if undefined
 */
string patchVersion();

/**
 * @return application version in form of "majorVersion.minorVersion.patchVersion"
 */
string applicationVersion();