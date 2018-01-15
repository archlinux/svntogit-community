# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgbase=python-distro
pkgname=('python-distro' 'python2-distro')
pkgver=1.2.0
pkgrel=2
pkgdesc='Linux OS platform information API'
url='https://github.com/nir0s/distro'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python-sphinx'
             'python2-setuptools' 'python2-sphinx')
checkdepends=('python-pytest' 'python2-pytest')
options=('!makeflags')
source=(${pkgbase}-${pkgver}.tar.gz::https://github.com/nir0s/distro/archive/v${pkgver}.tar.gz)
sha256sums=('eabd93bf9f6f14ff0ce676c384b5faf09e7a3692a765e048aed782aea17182fe')
sha512sums=('abce130d903f02bf6936e03f8e71c236752ef89f55b95ba256fd0eb4c212805327bec72f7fc6328256ee44a28891db6c0f66c9aedf260c7928844ec5895aca78')

prepare() {
  cp -a distro-${pkgver}{,-py2}
}

build() {
  (cd distro-${pkgver}
    python setup.py build
    make man SPHINXBUILD=sphinx-build
  )
  (cd distro-${pkgver}-py2
    python2 setup.py build
    make man SPHINXBUILD=sphinx-build2
  )
}

check() {
  (cd distro-${pkgver}
    py.test
  )
  (cd distro-${pkgver}-py2
    py.test2
  )
}

package_python-distro() {
  depends=('python' 'python-setuptools')
  cd distro-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGES -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-distro() {
  depends=('python2' 'python2-setuptools')
  cd distro-${pkgver}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGES -t "${pkgdir}/usr/share/doc/${pkgname}"
  mv "${pkgdir}/usr/bin/distro"{,2}
}

# vim: ts=2 sw=2 et:
