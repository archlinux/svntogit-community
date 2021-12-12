# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred.com>
# Contributor: Bogdan Szczurek <thebodzio@gmail.com>
# Contributor: Ismo Toijala <ismo.toijala@gmail.com>

pkgname=python-jsonschema
pkgver=3.2.0
pkgrel=6
pkgdesc="An implementation of JSON Schema validation for Python"
arch=('any')
url="https://pypi.python.org/pypi/jsonschema"
license=('MIT')
depends=('python-attrs' 'python-importlib-metadata' 'python-pyrsistent' 'python-setuptools')
makedepends=('python-setuptools-scm')
checkdepends=('python-twisted' 'python-idna' 'python-jsonpointer' 'python-strict-rfc3339'
              'python-rfc3987' 'python-webcolors')
source=("$pkgname-$pkgver.tar.bz2::https://github.com/Julian/jsonschema/archive/v$pkgver.tar.gz"
        $pkgname-webcolors.patch::https://github.com/Julian/jsonschema/commit/09595a50f507.patch)
sha512sums=('a575e9e7b0668220854e7ae45f2afd433643c3f0bfeb9769413cfc072ae01513a8d97bddbb6317f42348e09081e72bbad801d00ee5e3c0ac840bd19e934955cd'
            '31fac0a4ea816660cd815ba28578e8b80e69e884ec9a450a6bf582e7c311036025927239a72cac2b667547ce2c5088b310f006ecce88a2c926fa3915780b7dac')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cd jsonschema-$pkgver
  patch -Np1 -i ../$pkgname-webcolors.patch
}

build() {
  cd jsonschema-$pkgver
  python setup.py build
}

check() {
  cd jsonschema-$pkgver
  python setup.py install --root="$PWD/tmp_install" --optimize=1
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.10/site-packages" \
    JSON_SCHEMA_TEST_SUITE=json trial jsonschema
  python -m doctest README.rst
}

package() {
  cd jsonschema-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 json/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
