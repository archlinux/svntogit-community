# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: David Runge <dave@sleepmap.de>
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

_name=Jinja2
pkgbase=python-jinja
pkgname=('python-jinja' 'python2-jinja')
pkgver=2.10.1
pkgrel=2
pkgdesc="A simple pythonic template language written in Python"
arch=('any')
url="http://jinja.pocoo.org/"
license=('BSD')
makedepends=('python-setuptools' 'python2-setuptools' 'python-markupsafe'
             'python2-markupsafe')
checkdepends=('python-pytest' 'python2-pytest')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha256sums=('065c4f02ebe7f7cf559e49ee5a95fb800a9e4528727aec6f24402a5374c65013')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgbase}-${pkgver}"
  cd "${pkgbase}-${pkgver}"
}

build() {
  cd "${pkgbase}-${pkgver}"
  python setup.py build
  python2 setup.py build
}

check() {
  cd "${pkgbase}-${pkgver}"
  export PYTHONPATH="build:${PYTHONPATH}"
  py.test
  py.test2
}

package_python-jinja() {
  depends=('python-setuptools' 'python-markupsafe')
  optdepends=('python-babel: for i18n support')
  cd "${pkgbase}-${pkgver}"
  python setup.py install --skip-build \
    --optimize=1 \
    --prefix=/usr \
    --root="${pkgdir}/"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
  install -vDm 644 ext/Vim/jinja.vim \
    -t "${pkgdir}/usr/share/vim/vimfiles/syntax"
  install -vDm 644 ext/jinja.el -t "${pkgdir}/usr/share/emacs/site-lisp"
  install -vDm 644 AUTHORS {CHANGES,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-jinja() {
  depends=('python2-setuptools' 'python2-markupsafe')
  optdepends=('python2-babel: for i18n support')
  cd "${pkgbase}-${pkgver}"
  python2 setup.py install --skip-build \
    --optimize=1 \
    --prefix=/usr \
    --root="${pkgdir}/"
  install -vDm 644 LICENSE -t "$pkgdir/usr/share/licenses/$pkgname"
  install -vDm 644 AUTHORS {CHANGES,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}"
}
# vim:set ts=2 sw=2 et:
