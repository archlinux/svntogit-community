# Maintainer: Felix Yan <felixonmars@archlinux.org>
# Contributor: Daniel Wallace <danielwallace at gtmanfred.com>
# Contributor: Bogdan Szczurek <thebodzio@gmail.com>
# Contributor: Ismo Toijala <ismo.toijala@gmail.com>

pkgname=python-jsonschema
pkgver=3.2.0
pkgrel=4
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
            'c7e14ab01ca2adb1d4aa5b2670bd95d6e5141ade0f619463f35fe54066a69f045ee0ad929943c4af0edacddf4f93289b7318217bc0038069aa812b1a4428f54d')

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
  PYTHONPATH="$PWD/tmp_install/usr/lib/python3.9/site-packages" JSON_SCHEMA_TEST_SUITE=json trial3 jsonschema
  python -m doctest README.rst
}

package() {
  cd jsonschema-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
  install -D -m644 json/LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
