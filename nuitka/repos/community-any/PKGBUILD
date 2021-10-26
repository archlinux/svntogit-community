# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.17.4
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(python-appdirs scons)
makedepends=(python-setuptools)
checkdepends=(ccache fuse2 python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables'
            'pyside2: for using Qt5 APIs')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/N/${pkgname^}/${pkgname^}-${pkgver}.tar.gz")
sha512sums=('0f86def4243aa37d409d0820b8868fdf70528ee47844ef37b692da4c2e66f530e6710d2b5490003e8697a1e7dac9e3bdbe3f5a321b8a4c20259b178734b916e4')
b2sums=('2a30e62584323d1b1acb4cc1c9214e1bd20b9942c457368e0ac70d8f87524b503ec1a65880b6005c76b88aa4bbc55a1fd1c724fb354548d0f32c2747987ae7ba')

prepare() {
  cd ${pkgname^}-$pkgver
  # in our build environment /etc/os-release will not exist, but /usr/lib/os-release will
  sed -e 's|/etc/os-release|/usr/lib/os-release|' -i nuitka/utils/Utils.py
}

build() {
  cd ${pkgname^}-$pkgver
  python setup.py build
}

check() {
  cd ${pkgname^}-$pkgver
  # skip tests for other interpreters and those that require network access
  # NOTE: the test uses "strace", which is currently not supported by the reproducible build system
  ./tests/run-tests --no-other-python --skip-onefile-tests --skip-other-cpython-tests
}

package() {
  cd ${pkgname^}-$pkgver
  python setup.py install --optimize=1 --root="$pkgdir" --skip-build
  install -Dm644 {Changelog,Developer_Manual,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
