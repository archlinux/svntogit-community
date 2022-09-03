# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred.com>
# Contributor: Bogdan Szczurek <thebodzio@gmail.com>
# Contributor: Ismo Toijala <ismo.toijala@gmail.com>

pkgname=python-jsonschema
pkgver=4.15.0
pkgrel=1
pkgdesc="An implementation of JSON Schema validation for Python"
arch=('any')
url="https://pypi.python.org/pypi/jsonschema"
license=('MIT')
depends=('python-attrs' 'python-pyrsistent')
makedepends=('python-build' 'python-installer' 'python-hatchling' 'python-hatch-vcs'
             'python-hatch-fancy-pypi-readme')
checkdepends=('python-twisted' 'python-idna' 'python-jsonpointer' 'python-strict-rfc3339'
              'python-pip' 'python-rfc3987' 'python-webcolors')
source=("$pkgname-$pkgver.tar.bz2::https://github.com/Julian/jsonschema/archive/v$pkgver.tar.gz")
sha512sums=('bb1c7f52978cd3369013e172c3c1e4cdef937b7b380d71bd4ab0566ae1e8e95b62ca0af075acc48598574e7b86d0b5ddff4a87866612fde4c9f8ec32b3400993')

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
  install -Dm644 json/LICENSE -t "$pkgdir"/usr/share/licenses/$pkgname/
}
