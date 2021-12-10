# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgname=python-distro
pkgver=1.6.0
pkgrel=4
pkgdesc='Linux OS platform information API'
url='https://github.com/python-distro/distro'
arch=('any')
license=('Apache')
depends=('python' 'python-setuptools')
makedepends=('python-setuptools' 'python-sphinx')
checkdepends=('python-pytest')
options=('!makeflags')
source=(${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('48cff21ea152ec57c4505a72ffb1af5a138199f10ea908e138d16f48732f602a5b4f8bec2ee76b629981a1625453adf1b6895f4573229002b3b3ff7b76efbede')
b2sums=('558c4b1fcb93882b589375dd719f0f6100e4a78bbe9f167821c1588f82abbe00afd68f22f191f3722f0dd4358d76a6e295c8e69af29fdcd6ba7399d927e96f1c')

build() {
  (cd distro-${pkgver}
    python setup.py build
    make man SPHINXBUILD=sphinx-build
  )
}

check() {
  (cd distro-${pkgver}
    py.test
  )
}

package() {
  cd distro-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
