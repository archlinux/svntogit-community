# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Danilo Bargen <gezuru@gmail.com>
# Contributor: Simon Conseil <contact+aur at saimon dot org>
# Contributor: Jesus Alvarez

pkgname=python-jedi
_gitcommit=18f84d3af73c0de04883c10ab8745d7efb16593b
pkgver=0.16.0
pkgrel=1
pkgdesc="Awesome autocompletion for python"
url="https://github.com/davidhalter/jedi"
arch=('any')
license=('MIT')
depends=('python' 'python-parso')
makedepends=('git' 'python-setuptools')
checkdepends=('python-pytest' 'python-parso')
source=("git+https://github.com/davidhalter/jedi#commit=${_gitcommit}"
        git+https://github.com/davidhalter/typeshed
        0001-Jedi-understand-now-when-you-use-del-fixes-313.patch) 
sha256sums=('SKIP'
            'SKIP'
            'c8ac3df187d59eb8a9ea18290a829b4b23e16b131b5580a6677d208fe8726d81')

pkgver() {
  cd jedi
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  (cd jedi
    git submodule init
    git config submodule."jedi/third_party/typeshed".url "${srcdir}/typeshed"
    git submodule update --recursive

    patch -Np1 -i ${srcdir}/0001-Jedi-understand-now-when-you-use-del-fixes-313.patch
  )
}

build() {
  (cd jedi
    python setup.py build
  )
}

check() {
  (cd jedi
    pytest test
  )
}

package() {
  cd jedi
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst -t "$pkgdir/usr/share/doc/$pkgname"
}

# vim: ts=2 sw=2 et:
