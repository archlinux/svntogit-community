# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=1.2.1
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
b2sums=('d465f772502de5af6408367a3826f3dfed5087020dc4a8a77aae41e51b698dd591e21ba0d1a51965a31960ccc484e3a7896e173a848bf68f693984d0ddcd2937')

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
