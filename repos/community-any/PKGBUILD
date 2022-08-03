# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred.com>
# Contributor: Bogdan Szczurek <thebodzio@gmail.com>
# Contributor: Ismo Toijala <ismo.toijala@gmail.com>

pkgname=python-jsonschema
pkgver=4.9.0
pkgrel=1
pkgdesc="An implementation of JSON Schema validation for Python"
arch=('any')
url="https://pypi.python.org/pypi/jsonschema"
license=('MIT')
depends=('python-attrs' 'python-importlib-metadata' 'python-pyrsistent' 'python-rfc3987' 'python-jsonpointer' 'python-typing_extensions' 'python-webcolors')
makedepends=('python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs')
checkdepends=('python-twisted' 'python-idna' 'python-jsonpointer' 'python-strict-rfc3339'
              'python-rfc3987' 'python-webcolors' 'python-pip')
source=("$pkgname-$pkgver.tar.bz2::https://github.com/Julian/jsonschema/archive/v$pkgver.tar.gz")
sha512sums=('0ce28e0211651c8a7b1c923157c395888dd165f635f848db65c243def2f6bd921f2a21f69c3f7d2ceee6d6ae74d5272f9cac4ec243172d35da31908285dd61c5')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

build() {
  cd jsonschema-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  cd jsonschema-$pkgver
  python -m installer --destdir="$PWD/tmp_install" dist/*.whl
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" \
    JSON_SCHEMA_TEST_SUITE=json trial jsonschema
  python -m doctest README.rst
}

package() {
  cd jsonschema-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -D -m644 json/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
