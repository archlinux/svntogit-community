# Maintainer: Alexander F. Rødseth <xyproto@archlinux.org>
# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

pkgname=nuitka
pkgver=0.7.3
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=(any)
url='https://nuitka.net/'
license=(Apache)
depends=(python-appdirs scons)
makedepends=(python-setuptools)
checkdepends=(ccache fuse2 patchelf python-boto3 python-brotli strace)
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables'
            'pyside2: for using Qt5 APIs')
source=("https://files.pythonhosted.org/packages/source/N/${pkgname^}/${pkgname^}-${pkgver}.tar.gz")
sha512sums=('23f2b89886a1fc91499ba22393121e86f1cf6388276b2ee27f6e1f04fc0db665b35d81138b0f31473ed729500dd6611c12aa051a7fc64bad12881891cd0035bf')
b2sums=('ab45d31b474b281bac64b3a8caa1f16b97e416a16f7cf1499c781b354fd80d75c3e439df0f981bf7f2b48f7a0eb4e4981ae3906b4fd71afed6ed83e54cac7153')

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
  # skip tests for other interpreters, jinja2 and for those that require network access
  # NOTE: the test uses "strace", which is currently not supported by the reproducible build system
  ./tests/run-tests --no-other-python --skip-onefile-tests --skip-other-cpython-tests --skip-reflection-test
}

package() {
  cd ${pkgname^}-$pkgver
  python setup.py install --optimize=1 --root="$pkgdir" --skip-build
  install -Dm644 {Changelog,Developer_Manual,README}.rst -t "$pkgdir/usr/share/doc/$pkgname/"
}
