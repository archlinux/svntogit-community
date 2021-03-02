# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: David Runge <dave@sleepmap.de>
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

pkgname=python-jinja
pkgver=2.11.3
pkgrel=2
pkgdesc="A simple pythonic template language written in Python"
arch=('any')
url="https://palletsprojects.com/p/jinja/"
license=('BSD')
depends=('python-setuptools' 'python-markupsafe')
optdepends=('python-babel: for i18n support')
makedepends=('python-setuptools' 'python-markupsafe')
checkdepends=('python-pytest')
source=(https://files.pythonhosted.org/packages/source/J/Jinja2/Jinja2-$pkgver.tar.gz)
sha256sums=('a6d58433de0ae800347cab1fa3043cebbabe8baa9d29e668f1c768cb87a333c6')

build() {
  cd Jinja2-$pkgver
  python3 setup.py build
}

check() {
  cd Jinja2-$pkgver
  # https://github.com/pypa/setuptools/issues/2466
  PYTHONPATH=build/lib pytest \
   --deselect tests/test_bytecode_cache.py::TestByteCodeCache::test_simple \
   --deselect tests/test_loader.py::TestLoaders::test_package_loader \
   --deselect tests/test_loader.py::TestLoaders::test_choice_loader
}

package() {
  cd Jinja2-$pkgver
  python3 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst -t "$pkgdir/usr/share/licenses/$pkgname"

  install -Dm644 ext/Vim/jinja.vim -t "$pkgdir/usr/share/vim/vimfiles/syntax"
}

# vim:set ts=2 sw=2 et:
