# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: arch3y <arch3y[at]archstrike[dot]org>

_gitname=yara-python
pkgname=python-yara
pkgver=4.3.1
_gitcommit=37dcb76cd5a07c62e6ed2646968c496e22e70729
pkgrel=1
pkgdesc='Tool aimed at helping malware researchers to identify and classify malware samples'
url='https://github.com/VirusTotal/yara-python'
arch=('x86_64')
license=('Apache')
depends=('python' 'yara' 'libyara.so' 'glibc')
makedepends=('git' 'python-build' 'python-installer' 'python-wheel' 'python-setuptools')
checkdepends=('python-pytest')
source=(${pkgname}::git+"https://github.com/VirusTotal/${_gitname}#commit=${_gitcommit}")
sha512sums=('SKIP')

pkgver() {
  cd ${pkgname}
  git describe --tags --match 'v*' | sed 's/^v//;s/\([^-]*-g\)/r\1/;s/-/./g'
}

prepare() {
  cd ${pkgname}
  mkdir -p tests
  mv tests.py tests
}

build() {
  cd ${pkgname}
  python -m build --wheel --no-isolation \
    -C--global-option=build_ext \
    -C--global-option=--dynamic-linking
}

check() {
  cd ${pkgname}/tests
  local PYTHONVERSION="$(python -c 'import sys; print("{}{}".format(sys.version_info.major, sys.version_info.minor))')"
  PYTHONPATH="$PWD/../build/lib.linux-${CARCH}-cpython-${PYTHONVERSION}" \
    pytest tests.py
}

package() {
  cd ${pkgname}
  python -m installer --destdir="$pkgdir" dist/*.whl
  install -Dm 644 README.rst -t "${pkgdir}/usr/share/doc/${pkgname}"
  ln -s /usr/share/doc/yara/docs "${pkgdir}/usr/share/doc/${pkgname}/docs"
}

# vim: ts=2 sw=2 et:
