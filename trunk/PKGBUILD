# Maintainer: Felix Yan <felixonmars@archlinux.org>

pkgbase=python-importlib-metadata
pkgname=(python-importlib-metadata python2-importlib-metadata)
pkgver=0.9
pkgrel=1
pkgdesc="Read metadata from Python packages"
url="https://importlib-metadata.readthedocs.io"
license=('Apache')
arch=('any')
makedepends=('python-setuptools-scm' 'python2-setuptools-scm' 'python2-contextlib2'
             'python2-pathlib2' 'python2-configparser' 'python-zipp' 'python2-zipp')
checkdepends=('python-pip' 'python2-pip' 'python-pytest-runner' 'python2-pytest-runner'
              'python2-importlib_resources' 'python-wheel' 'python2-wheel')
source=("$pkgbase-$pkgver.tar.gz::https://gitlab.com/python-devs/importlib_metadata/-/archive/$pkgver/importlib_metadata-$pkgver.tar.bz2")
sha512sums=('c12d820c18be35a3734c336ba4c30905d4cd421e655b955025368c66fecb2beba9769c24cfbedc929bbce6828665051726495c2ec0b3e0684917033afad49613')

export SETUPTOOLS_SCM_PRETEND_VERSION=$pkgver

prepare() {
  cp -a importlib_metadata-$pkgver{,-py2}
  cd importlib_metadata-$pkgver
  sed -i 's/importlib_resources/importlib.resources/' importlib_metadata/tests/test_zip.py
}

build() {
  cd "$srcdir"/importlib_metadata-$pkgver
  python setup.py build

  cd "$srcdir"/importlib_metadata-$pkgver-py2
  python2 setup.py build
}

check() {
  # https://gitlab.com/python-devs/importlib_metadata/issues/41

  cd "$srcdir"/importlib_metadata-$pkgver
  python setup.py pytest --addopts "-k 'not test_file_hash_repr and not test_files_dist_info'"

  cd "$srcdir"/importlib_metadata-$pkgver-py2
  python2 setup.py pytest --addopts "-k 'not test_file_hash_repr and not test_files_dist_info'"
}

package_python-importlib-metadata() {
  depends=('python-zipp')

  cd importlib_metadata-$pkgver
  python setup.py install --root="$pkgdir" --optimize=1
}

package_python2-importlib-metadata() {
  depends=('python2-zipp' 'python2-configparser' 'python2-contextlib2' 'python2-pathlib2')

  cd importlib_metadata-$pkgver-py2
  python2 setup.py install --root="$pkgdir" --optimize=1
}
