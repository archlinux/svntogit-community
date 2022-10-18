# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=pypiserver
pkgver=1.5.1
pkgrel=1
pkgdesc="Minimal PyPI server for uploading and downloading packages with pip/easy_install"
arch=(any)
url="https://github.com/pypiserver/pypiserver"
license=(MIT zlib)
depends=(python python-pip)
makedepends=(python-build python-installer python-setuptools python-setuptools-git python-wheel)
checkdepends=(python-httpx python-passlib python-pip python-pytest python-watchdog python-webtest)
optdepends=(
  'python-passlib: for authentication'
  'python-setuptools: for new - still inactive - config module'
  'python-waitress: for waitress support'
  'python-watchdog: for cache'
)
source=($pkgname-$pkgver.tar.gz::https://github.com/$pkgname/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('35797c37ecfc2c7de21211c5c5f9c0edf98ba49e54fbee779099e411dde73377706aeddcd3dfb34c3ae2ef7d7f4ebf9146c3fb02b0778742d688f8ac17a64cfd')
b2sums=('23ceba3064da4a0d7a19af0a48f370913948dd8cec101cdee43f59c78087b71adcb0fb3a494ca1a94cf3cc2c42751f8710f9cf9037401d73bec7f94f300dbf6b')
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
