# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Danilo Bargen <gezuru@gmail.com>
# Contributor: Simon Conseil <contact+aur at saimon dot org>
# Contributor: Jesus Alvarez

pkgname=python-jedi
_gitcommit=8aaa8e00446f801c023bb4b056f51ac6f3d99e99
pkgver=0.17.0
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
        git+https://github.com/typeddjango/django-stubs)
sha256sums=('SKIP'
            'SKIP'
            'SKIP')

pkgver() {
  cd jedi
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd jedi
  git submodule init
  git config submodule."jedi/third_party/typeshed".url "${srcdir}/typeshed"
  git config submodule."jedi/third_party/django-stubs".url "${srcdir}/django-stubs"
  git submodule update --recursive

  # Inc difference limit in TestSetupReadline::test_import for py3.8
  git cherry-pick -n e7feeef64e9ef4a0e543afd13c9ed72decdcc533
}

build() {
  cd jedi
  python setup.py build
}

check() {
  cd jedi
  pytest test
}

package() {
  cd jedi
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname"
  install -Dm 644 CHANGELOG.rst README.rst -t "$pkgdir/usr/share/doc/$pkgname"
}

# vim: ts=2 sw=2 et:
