# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=pypiserver
pkgver=1.5.0
pkgrel=1
pkgdesc="Minimal PyPI server for uploading and downloading packages with pip/easy_install"
arch=(any)
url="https://github.com/pypiserver/pypiserver"
license=(MIT zlib)
depends=(python)
makedepends=(python-build python-installer python-setuptools python-setuptools-git python-wheel)
checkdepends=(python-httpx python-passlib python-pip python-pytest python-watchdog python-webtest)
optdepends=(
  'python-passlib: for authentication'
  'python-watchdog: for cache'
)
source=($pkgname-$pkgver.tar.gz::https://github.com/$pkgname/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('c93e724a3aa6ec265d483c2989129292a05132d3d52db6d9b9c1429610ee23b56e106c9389bdfaad142f34071ee258bdd4291668c11f8bb412df043bf4555611')
b2sums=('bfc0760982f97e93357702342eb5b1776f72c43e66742a8741ee2ba3109839006e99e49b65e04380097500c400e09bce77b74fc5f9072c7670349817ae3a73cb')
validpgpkeys=('0BFB950A1851C0E7EE46D9BCAF5C892A5573ABED') # Matthew Planchard (2020-06-22-mininix) <msplanchard@gmail.com>

build() {
  cd $pkgname-$pkgver
  python -m build --wheel --no-isolation
}

check() {
  local _site_packages=$(python -c "import site; print(site.getsitepackages()[0])")

  cd $pkgname-$pkgver
  python -m installer --destdir=test_dir dist/*.whl
  export PYTHONPATH="test_dir/$_site_packages:$PYTHONPATH"
  pytest -vv --ignore docker/test_docker.py -k "not test_twine"
}

package() {
  cd $pkgname-$pkgver
  python -m installer --destdir="$pkgdir" dist/$pkgname*.whl
  install -vDm 644 {AUTHORS,CHANGES,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
  install -vDm 644 LICENSE.txt -t "$pkgdir/usr/share/licenses/$pkgname/"
}
