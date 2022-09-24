# Maintainer: David Runge <dvzrv@archlinux.org>

_name=fastjsonschema
pkgname=python-fastjsonschema
_commit=1aad747bab39d4b1201ab99917463f4079955ecd # refs/tags/v2.16.2
pkgver=2.16.2
pkgrel=1
pkgdesc="Fast JSON schema validator for Python"
arch=(any)
url="https://github.com/horejsek/python-fastjsonschema"
license=(BSD)
depends=(python)
makedepends=(git python-build python-installer python-setuptools python-wheel)
checkdepends=(python-pytest)
# tests and additional assets not in sdist tarball: https://github.com/horejsek/python-fastjsonschema/issues/138
# source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
source=(
  git+https://github.com/horejsek/python-fastjsonschema#commit=$_commit
  git+https://github.com/json-schema-org/JSON-Schema-Test-Suite
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
  python -m build --wheel --no-isolation
}

check() {
  cd $pkgname
  pytest -vv -m "not benchmark"
}

package() {
  cd $pkgname
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 README.rst -t "$pkgdir/usr/share/doc/$pkgname"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
}
