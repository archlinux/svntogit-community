# Maintainer: Morten Linderud <foxboron@archlinux.no>
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor : Giedrius Slavinskas <giedrius25@gmail.com>

pkgname=python-babel
pkgver=2.12.1
_core=42
pkgrel=1
pkgdesc="A collection of tools for internationalizing Python applications"
url="http://babel.pocoo.org/"
license=("BSD")
arch=('any')
depends=('python' 'python-pytz')
makedepends=('python-setuptools')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-freezegun')
noextract=("cldr-core-$_core.zip")
source=("$pkgname-$pkgver.tar.gz::https://github.com/python-babel/babel/archive/v$pkgver.tar.gz"
        "cldr-core-$_core.zip::http://unicode.org/Public/cldr/$_core/core.zip"
        "cldr-common-$_core.0.zip::http://unicode.org/Public/cldr/$_core/cldr-common-$_core.0.zip"
        "$pkgname-$pkgver-fix-test.patch::https://github.com/python-babel/babel/commit/641f58c9951d9f5746cd63743dd337f1340d7bff.diff")
sha256sums=('37de3435fdec7c3267430765fc3ebe05cd234e65774ff1dc42a7b3b5cd39ef97'
            '53cd4fd1ac2ee4d4cbcae362e7af5d02e98e5e39c826ce9d723d41ca836fc846'
            '53cd4fd1ac2ee4d4cbcae362e7af5d02e98e5e39c826ce9d723d41ca836fc846'
            '629bbf810493ab2d4b104da7e007b8850bba7e5e39ab8065972a3a32b4093bc9')

prepare() {
  cp "$srcdir"/cldr-core-$_core.zip babel-$pkgver/cldr/cldr-core-$_core.zip
  cp "$srcdir"/cldr-common-$_core.0.zip babel-$pkgver/cldr/cldr-common-$_core.0.zip
  cd "babel-$pkgver"
  patch -Np1 < "$srcdir/python-babel-2.12.1-fix-test.patch"
}

build(){
  cd "babel-$pkgver"
  python setup.py import_cldr
  python setup.py build
}

check(){
  cd "babel-$pkgver"
  # the tests fail if running in the wrong timezone:
  # https://github.com/python-babel/babel/issues/757
  TZ=UTC python setup.py pytest
}

package_python-babel() {
  cd "babel-$pkgver"
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -D -m0644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
