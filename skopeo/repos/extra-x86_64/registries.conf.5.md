% registries.conf(5) Container Registries Configuration File
% Dan Walsh
% March 2018

## NAME
registries.conf - Syntax of Container Registries configuration file

## DESCRIPTION
The REGISTRIES configuration file specifies all of the available container registries for tools using shared container registries, but in a TOML format that can be more easily modified and versioned. `registries.conf` does not support recursive lists of registries. The default location for this configuration file is `/etc/containers/registries.conf`.

The only valid categories are: `registries.search`, `registries.insecure`, and `registries.block`.


## FORMAT
The [TOML format][toml] is used as the encoding of the configuration file.
Every option and subtable listed here is nested under a global "registries" table.
No bare options are used.

## Examples
    [registries.search]
    registries = ['quay.io', 'docker.io', 'registries.unsafe.com', 'registry.fedoraproject.org', 'registry.access.redhat.com']

    # If you need to access insecure registries, add the registry's fully-qualified name.
    # An insecure registry is one that does not have a valid SSL certificate or only does HTTP.
    [registries.insecure]
    registries = ['registries.unsafe.com']

    # If you need to block push access from a registry, uncomment the section below
    # and add the registries fully-qualified name.
    #
    # Docker only
    [registries.block]
    registries = []

## Files
/etc/conainers/registries.conf

## HISTORY
March 2018, Originally compiled by Dan Walsh <dwalsh@redhat.com>
