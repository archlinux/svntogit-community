# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: David Runge <dave@sleepmap.de>
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

pkgname=('python-jinja' 'python2-jinja')
pkgver=2.10.3
pkgrel=1
pkgdesc="A simple pythonic template language written in Python"
arch=('any')
url="https://palletsprojects.com/p/jinja/"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools' 'python-markupsafe'
             'python2-markupsafe')
checkdepends=('python-pytest' 'python2-pytest')
source=(https://files.pythonhosted.org/packages/source/J/Jinja2/Jinja2-$pkgver.tar.gz)
sha256sums=('9fe95f19286cfefaa917656583d020be14e7859c6b0252588391e47db34527de')

build() {
  cd Jinja2-$pkgver
  python3 setup.py build
}

check() {
  cd Jinja2-$pkgver
  export PYTHONPATH=build:$PYTHONPATH
  py.test
  py.test2
}

package_python-jinja() {
  depends=('python-setuptools' 'python-markupsafe')
  optdepends=('python-babel: for i18n support')

  cd Jinja2-$pkgver
  python3 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst -t "$pkgdir/usr/share/licenses/$pkgname"

  install -Dm644 ext/Vim/jinja.vim -t "$pkgdir/usr/share/vim/vimfiles/syntax"
  install -Dm644 ext/jinja.el -t "$pkgdir/usr/share/emacs/site-lisp"
}

package_python2-jinja() {
  depends=('python2-setuptools' 'python2-markupsafe')
  optdepends=('python2-babel: for i18n support')

  cd Jinja2-$pkgver
  python2 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst -t "$pkgdir/usr/share/licenses/$pkgname"
}

# vim:set ts=2 sw=2 et:
