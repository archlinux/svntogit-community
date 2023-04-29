# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Lance Chen <cyen0312@gmail.com>

_pypiname=wheel
pkgname=python-wheel
pkgver=0.40.0
pkgrel=3
pkgdesc="A built-package format for Python"
arch=(any)
url="https://pypi.python.org/pypi/wheel"
license=('MIT')
depends=('python-packaging')
optdepends=('python-keyring: for wheel.signatures'
            'python-xdg: for wheel.signatures')
makedepends=('python-setuptools' 'python-build' 'python-flit-core' 'python-installer')
checkdepends=('python-jsonschema' 'python-pytest' 'python-keyring' 'python-keyrings-alt'
              'python-xdg' 'python-pytest-cov')
source=("$pkgname-$pkgver.tar.gz::https://github.com/pypa/wheel/archive/$pkgver.tar.gz")
sha512sums=('f23bddfb0c23c77d16b24d9c6b132b0272830c89ae63ac672f204af665863a38779c142a72a66a33c615c4b52450d433b4edcbd333de4e0d418b4fbe836de953')

prepare() {
  cd wheel-$pkgver
  # https://github.com/pypa/wheel/pull/365 but why?
  rm -r src/wheel/vendored
  sed -i 's/from .vendored.packaging.requirements import Requirement/from packaging.requirements import Requirement/' src/wheel/metadata.py
  sed -i 's/from .vendored.packaging import tags/from packaging import tags/' src/wheel/bdist_wheel.py
  sed -i 's/from .vendored.packaging import version as _packaging_version/from packaging import version as _packaging_version/' src/wheel/bdist_wheel.py
  sed -i 's/from wheel.vendored.packaging import tags/from packaging import tags/' tests/test_bdist_wheel.py
}

build() {
  cd wheel-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  # Hack entry points by installing it

  cd wheel-$pkgver
  python -m installer --destdir="$PWD/tmp_install" dist/*.whl
  local site_packages=$(python -c "import site; print(site.getsitepackages()[0])")
  PYTHONPATH="$PWD/tmp_install/$site_packages" pytest
}

package() {
  cd wheel-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm644 LICENSE.txt -t "$pkgdir"/usr/share/licenses/$pkgname/
}
