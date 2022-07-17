# Maintainer: George Rawlinson <grawlinson@archlinux.org>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>

pkgname=python-distlib
_pkgname="${pkgname#python-}"
pkgver=0.3.5
pkgrel=1
pkgdesc='Low-level functions that relate to packaging and distribution of Python software'
arch=('any')
url='https://distlib.readthedocs.io'
license=('PSF')
depends=('python')
makedepends=('python-setuptools' 'python-build' 'python-installer' 'python-wheel')
source=("https://github.com/pypa/distlib/releases/download/$pkgver/distlib-$pkgver.tar.gz"{,.asc})
b2sums=('cded3b02873192b5ca77a654729d25ff7fb3d03bf81dc29a4031bee1cec3c26cbd400d1f3f346868a83d8986008439b119667f23f9878ec31eb59a3cefa1a7df'
        'SKIP')
validpgpkeys=('CA749061914EAC138E66EADB9147B477339A9B86') # Vinay Sajip <vinay_sajip@yahoo.co.uk>

prepare() {
  cd "$_pkgname-$pkgver"

  rm distlib/*.exe
}

build() {
  cd "$_pkgname-$pkgver"

  python -m build --wheel --no-isolation
}

check() {
  cd "$_pkgname-$pkgver"

  python tests/test_all.py
}

package() {
  cd "$_pkgname-$pkgver"

  python -m installer --destdir="$pkgdir" dist/*.whl
}
