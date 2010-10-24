# Maintainer: Chris Brannon <chris@the-brannons.com>
# Contributor : Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgbase=ipython
pkgname=(ipython ipython-docs)
pkgver=0.10.1
pkgrel=1
arch=('any')
url="http://ipython.scipy.org/"
license=('custom')
  makedepends=('python2') # for setup.py
source=("http://ipython.scipy.org/dist/$pkgver/$pkgbase-$pkgver.tar.gz")

build() {
  true
  # There's nothing to do here.  No configure, make, et cetera.  setup.py
  # does it all.
}

package_ipython() {
  pkgdesc="An enhanced Interactive Python shell."
  depends=('python2')
  optdepends=("wxpython: needed for ipythonx and ipython-wx"
              "twisted: networking-related tasks"
              "python-foolscap: for IPython's parallel computing features"
              "python-pexpect: for irunner"
              "python-nose: if you want to run IPython's test suite")

  cd "$srcdir/$pkgbase-$pkgver"

  install -Dm644 docs/source/license_and_copyright.txt "$pkgdir/usr/share/licenses/ipython/license.txt"
  python2 setup.py install --prefix=/usr --root="$pkgdir" --optimize=1
  rm -rf "$pkgdir/usr/share/doc"
  find "$pkgdir" -name '*.py' -print0 |xargs -0 \
    sed -i -e 's,^#!/usr/bin/env python$,#!/usr/bin/env python2,' \
    -e 's,^#!/usr/bin/python$,#!/usr/bin/python2,'
}

package_ipython-docs() {
  pkgdesc='Documentation and examples for IPython'

  cd "$srcdir/$pkgbase-$pkgver"

  install -Dm644 docs/source/license_and_copyright.txt "$pkgdir/usr/share/licenses/ipython-docs/license.txt"
  # Can I use $pkgname in that install command?

  python2 setup.py install --prefix=/usr --root="$pkgdir"
  rm -rf "$pkgdir/usr/lib" "$pkgdir/usr/bin" "$pkgdir/usr/share/man"
  # This seems wrong.  We're running setup.py for both
  # packages, and removing different things in each.
}
md5sums=('54ae47079b0e9a0998593a99ce76ec1f')
