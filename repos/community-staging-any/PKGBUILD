# Maintainer: Morten Linderud <foxboron@archlinux.no>
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor : Giedrius Slavinskas <giedrius25@gmail.com>

pkgbase=python-babel
pkgname=(python-babel python2-babel)
pkgver=2.7.0
_core=35.1
pkgrel=3
pkgdesc="A collection of tools for internationalizing Python applications"
url="http://babel.pocoo.org/"
license=("BSD")
arch=('any')
makedepends=('python' 'python2'
             'python-setuptools' 'python2-setuptools'
             'python-pytz' 'python2-pytz')
checkdepends=('python-pytest' 'python-pytest-runner' 'python-freezegun'
	      'python-pytest-runner' 'python2-pytest-runner' 'python2-freezegun')
noextract=("cldr-core-$_core.zip")
source=("$pkgbase-$pkgver.tar.gz::https://github.com/python-babel/babel/archive/v$pkgver.tar.gz"
        "cldr-core-$_core.zip::http://unicode.org/Public/cldr/$_core/core.zip")
sha256sums=('d31a563d7b573f2544d49fecc22b58d470a624ebb63fe41583502095e266c462'
            'e2ede8cb8f9c29157e281ee9e696ce540a72c598841bed595a406b710eea87b0')

prepare() {
  cp -a babel-$pkgver{,-py2}
  cp "$srcdir"/cldr-core-$_core.zip babel-$pkgver-py2/cldr/cldr-core-$_core.zip
  cp "$srcdir"/cldr-core-$_core.zip babel-$pkgver/cldr/cldr-core-$_core.zip
}

build(){
  cd "$srcdir/babel-$pkgver"
  python setup.py import_cldr
  python setup.py build

  cd "$srcdir/babel-$pkgver-py2"
  python2 setup.py import_cldr
  python2 setup.py build
}

check(){
  cd "$srcdir/babel-$pkgver"
  python setup.py pytest

  cd "$srcdir/babel-$pkgver-py2"
  python2 setup.py pytest
}

package_python-babel() {
  depends=('python' 'python-pytz')

  cd "$srcdir"/babel-${pkgver}
  python setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -D -m0644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}

package_python2-babel() {
  depends=('python2' 'python2-pytz')

  cd "$srcdir"/babel-${pkgver}-py2
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  mv "$pkgdir"/usr/bin/pybabel "$pkgdir"/usr/bin/pybabel2
  install -D -m0644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
}
