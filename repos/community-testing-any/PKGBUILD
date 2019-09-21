# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Danilo Bargen <gezuru@gmail.com>
# Contributor: Simon Conseil <contact+aur at saimon dot org>
# Contributor: Jesus Alvarez

pkgbase=python-jedi
pkgname=('python2-jedi' 'python-jedi')
_gitcommit=005f69390c4b1a3b864e7373cfcbdaf95e65411d
pkgver=0.15.1
pkgrel=1
pkgdesc="Awesome autocompletion for python"
url="https://github.com/davidhalter/jedi"
arch=('any')
license=('MIT')
makedepends=('git' 'python2-setuptools' 'python-setuptools')
checkdepends=('python-pytest' 'python2-pytest' 'python-parso' 'python2-parso')
source=("git+https://github.com/davidhalter/jedi#commit=${_gitcommit}"
        git+https://github.com/davidhalter/typeshed
        jedi-fix-pytest5.1.2.patch)
sha256sums=('SKIP'
            'SKIP'
            'a02b616a3cdd178de894abb6212f6ce86432915dc5c12cd156da043433e6b153')

pkgver() {
  cd jedi
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  (cd jedi
    git submodule init
    git config submodule."jedi/third_party/typeshed".url "${srcdir}/typeshed"
    git submodule update --recursive
    patch -Np1 < ../jedi-fix-pytest5.1.2.patch
  )
  cp -a jedi{,-py2}
}

build() {
  (cd jedi
    python setup.py build
  )
  (cd jedi-py2
    python2 setup.py build
  )
}

check() {
  (cd jedi
    pytest test
  )
  (cd jedi-py2
    pytest2 test
  )
}

package_python-jedi() {
  pkgdesc="Awesome autocompletion for python"
  depends=('python' 'python-parso')
  cd jedi
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst -t "$pkgdir/usr/share/doc/$pkgname"
}

package_python2-jedi() {
  pkgdesc="Awesome autocompletion for python2"
  depends=('python2' 'python2-parso')
  cd jedi-py2
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst -t "$pkgdir/usr/share/doc/$pkgname"
}

# vim: ts=2 sw=2 et:
