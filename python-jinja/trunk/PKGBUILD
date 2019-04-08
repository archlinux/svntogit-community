# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

pkgname=('python-jinja' 'python2-jinja')
pkgver=2.10.1
pkgrel=1
pkgdesc="A simple pythonic template language written in Python"
arch=('any')
url="http://jinja.pocoo.org/"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools' 'python-markupsafe'
             'python2-markupsafe')
source=(https://pypi.org/packages/source/J/Jinja2/Jinja2-$pkgver.tar.gz)
sha256sums=('065c4f02ebe7f7cf559e49ee5a95fb800a9e4528727aec6f24402a5374c65013')

build() {
  cd "$srcdir"

  rm -rf python{2,3}-build
  for builddir in python{2,3}-build; do
    cp -r Jinja2-$pkgver $builddir
    pushd $builddir
    ${builddir%-build} setup.py build
    popd
  done
}

package_python-jinja() {
  depends=('python-setuptools' 'python-markupsafe')

  cd "$srcdir/python3-build"

  python3 setup.py install --root="$pkgdir" -O1

  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

package_python2-jinja() {
  depends=('python2-setuptools' 'python2-markupsafe')

  cd "$srcdir/python2-build"

  python2 setup.py install --root="$pkgdir" -O1

  install -Dm644 LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
}

# vim:set ts=2 sw=2 et:
