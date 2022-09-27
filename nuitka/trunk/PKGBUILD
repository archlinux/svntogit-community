# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=1.0.8
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(patchelf python-appdirs scons)
makedepends=(gdb python-build python-installer python-setuptools python-wheel)
checkdepends=(ccache fuse2 python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'pyside2: for using Qt5 APIs')
source=("https://nuitka.net/releases/${pkgname^}-${pkgver}.tar.bz2")
b2sums=('edcb8bcce156c15f6518804c6dfb65799bf046e724cbbea149665ad351f57295e33541f82319664a77a7d8c062419cca306a724217d1d92e870f1517a9e1bf47')

prepare() {
  cd ${pkgname^}-$pkgver
  # in the build environment /etc/os-release does not exist, but /usr/lib/os-release does
  sed -e 's,/etc/os-release,/usr/lib/os-release,' -i nuitka/utils/Utils.py
}

build() {
  cd ${pkgname^}-$pkgver
  python -m build --wheel --no-isolation
}

# TODO: Make tests pass and/or report issues upstream (some have already been reported)
check() {
 cd ${pkgname^}-$pkgver/tests
 rm -r programs/pkgutil_usage
 ./run-tests --no-other-python --skip-onefile-tests --skip-other-cpython-tests --skip-reflection-test
}

package() {
  cd ${pkgname^}-$pkgver
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -vDm 644 {Changelog,Developer_Manual,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
