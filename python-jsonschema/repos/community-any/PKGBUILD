# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred.com>
# Contributor: Bogdan Szczurek <thebodzio@gmail.com>
# Contributor: Ismo Toijala <ismo.toijala@gmail.com>

pkgname=python-jsonschema
pkgver=4.14.0
pkgrel=1
pkgdesc="An implementation of JSON Schema validation for Python"
arch=('any')
url="https://pypi.python.org/pypi/jsonschema"
license=('MIT')
depends=('python-attrs' 'python-importlib-metadata' 'python-pyrsistent' 'python-rfc3987' 'python-jsonpointer' 'python-typing_extensions' 'python-webcolors')
makedepends=('python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs' 'python-hatch-fancy-pypi-readme')
checkdepends=('python-twisted' 'python-idna' 'python-jsonpointer' 'python-strict-rfc3339'
              'python-rfc3987' 'python-webcolors' 'python-pip')
source=("$pkgname-$pkgver.tar.bz2::https://github.com/Julian/jsonschema/archive/v$pkgver.tar.gz")
sha512sums=('58201fd7c58fe966807737cca45707ae2e3a980f3cc6d5c72c4342bad927de0fbd0156578c06cf39ad280e0026742a2f492388a0b7d4063507174b319c38071e')

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
