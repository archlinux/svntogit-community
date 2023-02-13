# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=1.4.6
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
b2sums=('a1154bdb180ab6af43962f4b1a6fc686f6daa901757300e1ff90353bb89f63c6dd8df751e31264c8b58ebce7efbee79465f88f2601a7361827d27351fb49e25e')

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
