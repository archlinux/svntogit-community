# Maintainer: Chris Brannon <cmbrannon79@gmail.com>
# Contributor : Douglas Soares de Andrade <dsa@aur.archlinux.org>

pkgbase=ipython
pkgname=(ipython ipython-docs)
pkgver=0.10
pkgrel=3
arch=('any')
url="http://ipython.scipy.org/"
license=('custom')
  makedepends=('python') # for setup.py
source=("http://ipython.scipy.org/dist/$pkgver/$pkgbase-$pkgver.tar.gz")
md5sums=('dd10cd1b622c16c1afca2239fcc0dfdf')

build() {
  true
  # There's nothing to do here.  No configure, make, et cetera.  setup.py
  # does it all.
}

package_ipython() {
  pkgdesc="An enhanced Interactive Python shell."
  depends=('python')
  optdepends=("wxpython: needed for ipythonx and ipython-wx"
              "twisted: networking-related tasks"
              "python-foolscap: for IPython's parallel computing features"
              "python-pexpect: for irunner"
              "python-nose: if you want to run IPython's test suite")

  cd "$srcdir/$pkgbase-$pkgver"

  install -Dm644 docs/source/license_and_copyright.txt "$pkgdir/usr/share/licenses/ipython/license.txt" || return 1
  python setup.py install --prefix=/usr --root="$pkgdir" || return 1
  rm -rf "$pkgdir/usr/share/doc"
}

package_ipython-docs() {
  pkgdesc='Documentation and examples for IPython'

  cd "$srcdir/$pkgbase-$pkgver"

  install -Dm644 docs/source/license_and_copyright.txt "$pkgdir/usr/share/licenses/ipython-docs/license.txt" || return 1
  # Can I use $pkgname in that install command?

  python setup.py install --prefix=/usr --root="$pkgdir" || return 1
  rm -rf "$pkgdir/usr/lib" "$pkgdir/usr/bin" "$pkgdir/usr/share/man"
  # This seems wrong.  We're running setup.py for both
  # packages, and removing different things in each.
}
