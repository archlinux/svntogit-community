# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.6.17.6
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
sha512sums=('af6d2fbb7b33598a1358e08b8c920b1408d12afabc146febe671b0c7b25185b85c7585391d49fae14567c59b82d3a7911192eb1d2e3a84e6f33514e03a0751a5')
b2sums=('b9a088d2356de9b802a99882cdd1bb67d29bcfe5c4770aef962e9ccf26dd9b9a7f13760125999590bf6920196a67f4a50e3620606916b2dec32a8aeb8b0116cf')

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
