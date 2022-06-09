#!/usr/bin/electron

const name = "react-native-debugger";

const {app} = require("electron");
const fs = require("fs");
const {dirname, join} = require("path");

// Set environment variables.
process.env.PACKAGE = 'no';

// Change command name.
const fd = fs.openSync("/proc/self/comm", fs.constants.O_WRONLY);
fs.writeSync(fd, name);
fs.closeSync(fd);

// Remove first command line argument (/usr/bin/electron).
process.argv.splice(0, 1);

// Set application paths.
const appPath = join(dirname(__dirname), "lib", name);
const packageJson = require(join(appPath, "package.json"));
const productName = packageJson.productName;
app.setAppPath(appPath);
app.setDesktopName(name + ".desktop");
app.setName(productName);
app.setPath("userCache", join(app.getPath("cache"), productName));
app.setPath("userData", join(app.getPath("appData"), productName));
app.setVersion(packageJson.version);

// Run the application.
require("module")._load(appPath, module, true);
