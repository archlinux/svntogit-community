# Maintainer: David Runge <dvzrv@archlinux.org>

_name=fastjsonschema
pkgname=python-fastjsonschema
_commit=d03f3835da4899bdeb597a9d3f30a709e7c3254f  # refs/tags/v2.15.3
pkgver=2.15.3
pkgrel=1
pkgdesc="Fast JSON schema validator for Python"
arch=(any)
url="https://github.com/horejsek/python-fastjsonschema"
license=(BSD)
depends=(python)
makedepends=(git python-setuptools)
checkdepends=(python-pytest)
# tests and additional assets not in sdist tarball: https://github.com/horejsek/python-fastjsonschema/issues/138
# source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
source=(
  "git+https://github.com/horejsek/python-fastjsonschema#commit=$_commit"
  "git+https://github.com/json-schema-org/JSON-Schema-Test-Suite"
)
sha512sums=('SKIP'
            'SKIP')
b2sums=('SKIP'
        'SKIP')

prepare() {
  cd $pkgname
  git submodule init
  git config submodule.JSON-Schema-Test-Suite.url ../JSON-Schema-Test-Suite
  git submodule update
}

build() {
  cd $pkgname
  python setup.py build
}

check() {
  cd $pkgname
  PYTHONPATH="build:$PYTHONPATH"
  # disable failing test (probably related to missing pytest-cache):
  # https://github.com/horejsek/python-fastjsonschema/issues/139
  pytest -v -m "not benchmark" -k "not test_compile_to_code_custom_format_with_refs"
}

package() {
  cd $pkgname
  python setup.py install --optimize=1 --root="$pkgdir"
  install -vDm 644 README.rst -t "$pkgdir/usr/share/doc/$pkgname"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}
