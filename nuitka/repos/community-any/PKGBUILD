# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=1.5
pkgrel=2
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
b2sums=('f6afcf81a2e52313c4a2fa760b2275a59feeb560ec55eef8bb4baf12bbc0b160863dbc6fffae291edec4d9e63da2d462d0338c8a5fcfccf7d8b34f4a0b355163')

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
