# Maintainer: Evangelos Foutras <evangelos@foutrelis.com>
# Contributor: David Runge <dave@sleepmap.de>
# Contributor: Peter Baldwin <bald_pete@hotmail.com>

pkgname=python-jinja
pkgver=3.1.0
pkgrel=1
pkgdesc="A simple pythonic template language written in Python"
arch=('any')
url="https://palletsprojects.com/p/jinja/"
license=('BSD')
depends=('python-setuptools' 'python-markupsafe')
optdepends=('python-babel: for i18n support')
checkdepends=('python-pytest')
source=(https://files.pythonhosted.org/packages/source/J/Jinja2/Jinja2-$pkgver.tar.gz)
sha256sums=('a2f09a92f358b96b5f6ca6ecb4502669c4acb55d8733bbb2b2c9c4af5564c605')

build() {
  cd Jinja2-$pkgver
  python3 setup.py build
}

check() {
  cd Jinja2-$pkgver
  # https://github.com/pypa/setuptools/issues/2466
  PYTHONPATH=build/lib pytest \
    --deselect tests/test_loader.py::test_package_dir_list \
    --deselect tests/test_loader.py::test_package_dir_source \
    --deselect tests/test_loader.py::test_package_file_list \
    --deselect tests/test_loader.py::test_package_file_source \
    --deselect tests/test_loader.py::test_package_zip_list \
    --deselect tests/test_loader.py::test_package_zip_omit_curdir \
    --deselect tests/test_loader.py::test_package_zip_source
}

package() {
  cd Jinja2-$pkgver
  python3 setup.py install --root="$pkgdir" --optimize=1 --skip-build
  install -Dm644 LICENSE.rst -t "$pkgdir/usr/share/licenses/$pkgname"
}

# vim:set ts=2 sw=2 et:
