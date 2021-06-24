## 1.0.1 (June 24, 2021)

ENHANCEMENTS:

* json-output: The JSON plan output now indicates which state values are sensitive. ([#28889](https://github.com/hashicorp/terraform/issues/28889))
* cli: The darwin builds can now make use of the host DNS resolver, which will fix many network related issues on MacOS.

BUG FIXES:

* backend/remote: Fix faulty Terraform Cloud version check when migrating state to the remote backend with multiple local workspaces ([#28864](https://github.com/hashicorp/terraform/issues/28864))
* cli: Fix crash with deposed instances in json plan output ([#28922](https://github.com/hashicorp/terraform/issues/28922))
* core: Fix crash when provider modifies and unknown block during plan ([#28941](https://github.com/hashicorp/terraform/issues/28941))
* core: Diagnostic context was missing for some errors when validating blocks ([#28979](https://github.com/hashicorp/terraform/issues/28979))
* core: Fix crash when calling `setproduct` with unknown values ([#28984](https://github.com/hashicorp/terraform/issues/28984))
* json-output: Fix an issue where the JSON configuration representation was missing fully-unwrapped references. ([#8884](https://github.com/hashicorp/terraform/issues/8884))
* json-output: Fix JSON plan resource drift to remove unchanged resources. ([#28975](https://github.com/hashicorp/terraform/issues/28975))
