#!/usr/bin/electron

const name = 'code'

const app = require('electron').app;
const path = require('path');
const fs = require("fs");
const Module = require("module");
const {join} = require("path");
const vm = require("vm");

// Change command name.
const fd = fs.openSync('/proc/self/comm', fs.constants.O_WRONLY);
fs.writeSync(fd, name);
fs.closeSync(fd);

// Remove first command line argument (/usr/bin/electron).
process.argv.splice(0, 1);

// Set application paths.
const appPath = path.join(path.dirname(__dirname), 'lib', name);
const packageJson = require(path.join(appPath, 'package.json'));
const productName = 'code-oss'
app.setAppPath(appPath);
app.setDesktopName(name + '.desktop');
app.setName(productName);
app.setPath('userCache', path.join(app.getPath('cache'), productName));
app.setPath('userData', path.join(app.getPath('appData'), productName));
app.setVersion(packageJson.version);

// Run the application.
require('module')._load(appPath, module, true);

