# Quicklisp beta FAQ

Frequently asked questions for the [Quicklisp beta](index.html).

**How can I add a project to Quicklisp?**
It's easy to request that a library you write or find be added to Quicklisp.
If it's a public project available via HTTP, CVS, git, darcs, etc., please
[create a request](http://github.com/quicklisp/quicklisp-projects/issues) with
info about where to find it.

There are two blog posts on the topic: [Getting a library into
Quicklisp](http://blog.quicklisp.org/2015/01/getting-library-into-
quicklisp.html) and [Some problems when adding libraries to
Quicklisp](http://blog.quicklisp.org/2015/01/some-problems-when-adding-
libraries-to.html).

You will be able to make your own private repositories of Quicklisp software
(called _dists_ ), but it's not documented right now.

**How is Quicklisp related to ASDF?**
Quicklisp has an archive of project files and metadata about project
relationships. It can download a project and its dependencies. ASDF is used to
actually compile and load the project and its dependencies.

ASDF is a little like `make` and Quicklisp is a little like a Linux package
manager.

**I am behind a firewall. Can I use a proxy?**
Yes. After loading `quicklisp.lisp`, you can use the `:proxy` option of
`quicklisp-quickstart:install`:



        (quicklisp-quickstart:install :proxy "http://myproxy.site.com:8080/")


Only plain HTTP (no SSL) is supported at this time. Proxy authentication is
also not yet supported.

You can change the proxy value after initial installation with this:



        (setf (ql-config:config-value "proxy-url") "http://proxy.value.here")


The value is preserved between Quicklisp sessions.

It's possible to use an intermediate proxy to do SSL, authentication, and more
with Quicklisp. See [Quicklisp with an Authenticating
Proxy](http://netprophetblog.blogspot.com/2014/02/tool-posting-quicklisp-
with.html) for details.

**Can I install somewhere other than ~/quicklisp?**
Yes. After loading `quicklisp.lisp`, you can use the `:path` option of
`quicklisp-quickstart:install`:



        (quicklisp-quickstart:install :path ".quicklisp/")


You can also change the Quicklisp path after installation simply by renaming
`quicklisp` to something else.

**I got this error in Emacs when using quicklisp-slime-helper: _Searching for
program: no such file or directory, lisp_**
This error occurs because you need to tell slime what Lisp implementation to
use by setting an appropriate value for `inferior-lisp-program`. For example,
if you use SBCL, you can add this to your .emacs file:



    (setq inferior-lisp-program "sbcl")


The value can also be a full pathname, e.g. `/home/xach/bin/clisp`.

There are other ways to configure which CL implementation is used when
starting slime. See [the slime manual](http://common-
lisp.net/project/slime/doc/html/Multiple-Lisps.html) for more details.

**I got this error: _Quicklisp has already been installed._**
This error occurs if you load quicklisp.lisp after the initial installation.
After Quicklisp has been installed, you don't need to load quicklisp.lisp
again. To load Quicklisp into your Lisp, you can use this:



        (load (merge-pathnames "quicklisp/setup.lisp"
    			   (user-homedir-pathname)))


To automatically load Quicklisp when your Lisp starts, you can use this:



        (ql:add-to-init-file)


**Can I load a local project that isn't part of Quicklisp?**
Yes. The easiest way is to put the project's directory in Quicklisp's `local-
projects` directory. For example:



        $ **cd ~/quicklisp/local-projects/**
        $ **git clone git://github.com/xach/format-time.git**


The project will then be loadable via `(ql:quickload "format-time")`

Also, any system file that can be found via ASDF's [source registry
system](http://common-lisp.net/project/asdf/asdf.html#Configuring-ASDF) can be
loaded with `ql:quickload`.

For example, if you have a system file `my-project.asd` in `/projects/my-
project/`, you can do something like this:



        (push #p"/projects/my-project/" asdf:*central-registry*)
        (ql:quickload "my-project")


If `my-project` depends on systems that are available via Quicklisp that are
not already installed, they will be automatically installed.

**Can I load a local version of a project instead of Quicklisp's version?**
Yes. Any system file that can be found in a local project directory or in
ASDF's source registry system will be loaded in preference to Quicklisp's
version of the system. See _Can I load a local project that isn't part of
Quicklisp?_ for an example.

**Do I have to install Quicklisp separately for multiple Lisps?**
No. You can use one installation of Quicklisp among multiple implementations
of Common Lisp. As long as they load the same `setup.lisp`, they will share
metadata and software files. FASL files are automatically separated by ASDF's
output translations mechanism.

**Can I install or move Quicklisp somewhere other than ~/quicklisp/?**
Yes. During installation, you can use the `:path` option to install it to any
location you want. For example:



        (quicklisp-quickstart:install :path "/Users/xach/.quicklisp/")


After installation, you can also move the `quicklisp` directory to a different
place. The directory is self-contained and can be renamed or moved anywhere
you like.

Making use of Quicklisp from any directory is a matter of loading the
`setup.lisp` file from that directory. All other work is done relative to that
file.

**How can I support Quicklisp?**
There are a few ways:

  * [Make a donation](/donations.html)
  * Write about Quicklisp online (some people don't know about it)
  * Write some great Lisp libraries and tell me to add them to Quicklisp

All help is greatly appreciated.

[Zach Beane](mailto:zach@quicklisp.org) 2020-11-16

