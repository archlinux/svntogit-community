# Maintainer: David Runge <dvzrv@archlinux.org>
# Contributor: Alexander F. Rødseth <xyproto@archlinux.org>
# Contributor: Panagiotis Mavrogiorgos <pmav99@gmail.com>

_name=Nuitka
pkgname=nuitka
pkgver=0.6.12.2
pkgrel=1
pkgdesc='Python compiler with full language support and CPython compatibility'
arch=('any')
url='https://nuitka.net/'
license=('Apache')
depends=('python-appdirs' 'scons')
makedepends=('python-setuptools')
checkdepends=('ccache' 'fuse2' 'python-boto3' 'python-brotli' 'strace')
optdepends=('ccache: for build caching'
            'chrpath: for building standalone executables')
options=(!emptydirs)
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz")
sha512sums=('efc987fd3695533a160f7631b9295aa43cf4c01bbc46ec9f36503940129b5c07b96bd9928f176c300e1f1afb55d5d9b6bdd03702f5ecfc2085efc3141768ef5f')
b2sums=('a85387249500fffebedfc637ecabaf2a2b7f92c42bc5389d1bc2640c2cb27822b46b597b581c0c0aac4b6fb64bde35a7f811b3e1ee461d7ba5d6148fc545f681')

prepare() {
  mv -v "${_name}-${pkgver}" "${pkgname}-${pkgver}"
}

build() {
  cd "${pkgname}-${pkgver}"
  python setup.py build
}

check() {
  cd "${pkgname}-${pkgver}"
  # skip tests for other interpreters and those that require network access
  ./tests/run-tests --no-other-python --skip-reflection-test --skip-other-cpython-tests --skip-onefile-tests
}

package() {
  cd "${pkgname}-${pkgver}"
  python setup.py install --skip-build \
                          --optimize=1 \
                          --root="${pkgdir}"
  install -vDm 644 {Changelog,Developer_Manual,README}.rst \
    -t "${pkgdir}/usr/share/doc/${pkgname}/"
}
