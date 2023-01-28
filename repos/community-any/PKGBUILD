# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=1.4
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(libxml2 patchelf python-appdirs python-setuptools python-wheel scons)
makedepends=(gdb python-build python-installer)
checkdepends=(ccache fuse2 python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'pyside2: for using Qt5 APIs')
source=("https://nuitka.net/releases/${pkgname^}-${pkgver}.tar.bz2")
b2sums=('ba6a4ce0ad69142cfab6a0b3bfe018b1699af0f17aaa6b2d0c9fcadd66395179fe95c343017e8b229c7cc5b52c056beac30c3e97d17759e94efb2fa802332f25')

prepare() {
  cd ${pkgname^}-$pkgver
  # in the build environment /etc/os-release does not exist, but /usr/lib/os-release does
  sed -e 's,/etc/os-release,/usr/lib/os-release,' -i nuitka/utils/Utils.py
}

build() {
  cd ${pkgname^}-$pkgver
  python -m build --wheel --no-isolation
}

# TODO: Find a way to run the tests that does not take that long.
# TODO: Make all tests pass and/or report issues upstream (some have already been reported).
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

# getver: github.com/Nuitka/Nuitka
