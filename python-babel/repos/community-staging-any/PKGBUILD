# Maintainer: Morten Linderud <foxboron@archlinux.no>
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor : Giedrius Slavinskas <giedrius25@gmail.com>

pkgname=python-babel
pkgver=2.8.1
_core=36
pkgrel=2
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
        "python-3.9.patch")
sha256sums=('2324e41ffb439a83748813e54718574c094222bb32996d466958a7a3d6c23a47'
            '07279e56c1f4266d140b907ef3ec379dce0a99542303a9628562ac5fe460ba43'
            '13adbc61cf0c59f215f38cd5b1a4dc3c29f2e35c9e9d054f64a9f03308401b0a')

prepare() {
  # Python 3.9 fixes
  patch -Np1 -d babel-$pkgver <python-3.9.patch

  cp "$srcdir"/cldr-core-$_core.zip babel-$pkgver/cldr/cldr-core-$_core.zip
}

build(){
  cd "$srcdir/babel-$pkgver"
  python setup.py import_cldr
  python setup.py build
}

check(){
  cd "$srcdir/babel-$pkgver"
  # the tests fail if running in the wrong timezone:
  # https://github.com/python-babel/babel/issues/757
  TZ=UTC python setup.py pytest
}

package_python-babel() {
  cd "$srcdir"/babel-${pkgver}
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -D -m0644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
