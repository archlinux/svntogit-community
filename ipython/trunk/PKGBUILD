# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Chris Brannon <chris@the-brannons.com>
# Contributor : Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgbase=ipython
pkgname=(ipython ipython-docs)
pkgver=0.11
pkgrel=1
arch=('any')
url="http://ipython.org"
license=('Modified BSD')
makedepends=('python2') # for setup.py
source=("http://archive.ipython.org/release/$pkgver/ipython-$pkgver.tar.gz")
md5sums=('efc899e752a4a4a67a99575cea1719ef')

build() {
  true
  # There's nothing to do here.  No configure, make, et cetera.  setup.py
  # does it all.
}

package_ipython() {
  pkgdesc="An enhanced Interactive Python2 shell."
  depends=('python2')
  optdepends=("wxpython: needed for ipythonx and ipython-wx"
              "twisted: networking-related tasks"
              "python-foolscap: for IPython's parallel computing features"
              "python-pexpect: for irunner"
              "python2-nose: if you want to run IPython's test suite"
              "python2-pyqt: for ipython-qtconsole"
              "python2-sip: for ipython-qtconsole"
              "python2-pyzmq: for ipython-qtconsole")

  cd "$srcdir/$pkgbase-$pkgver"

  python2 setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  rm -rf "$pkgdir/usr/share/doc"
  find "$pkgdir" -name '*.py' -print0 |xargs -0 \
    sed -i -e 's,^#!/usr/bin/env python$,#!/usr/bin/env python2,' \
    -e 's,^#!/usr/bin/python$,#!/usr/bin/python2,'
}

package_ipython-docs() {
  pkgdesc='Documentation and examples for IPython'

  cd "$srcdir/$pkgbase-$pkgver"

  python2 setup.py install --prefix=/usr --root="$pkgdir"
  rm -rf "$pkgdir/usr/lib" "$pkgdir/usr/bin" "$pkgdir/usr/share/man"
  # This seems wrong.  We're running setup.py for both
  # packages, and removing different things in each.
}

