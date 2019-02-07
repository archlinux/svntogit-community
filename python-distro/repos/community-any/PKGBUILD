# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgbase=python-distro
pkgname=('python-distro' 'python2-distro')
pkgver=1.4.0
pkgrel=1
pkgdesc='Linux OS platform information API'
url='https://github.com/nir0s/distro'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python-sphinx'
             'python2-setuptools' 'python2-sphinx')
checkdepends=('python-pytest' 'python2-pytest')
options=('!makeflags')
source=(${pkgbase}-${pkgver}.tar.gz::https://github.com/nir0s/distro/archive/v${pkgver}.tar.gz)
sha256sums=('47c5b3c88b898e4f4c8eb6849ee379ac89bde9a16cdf6f98e3ef85eb2284980d')
sha512sums=('4633136551a5814e1c0085ed500d1b555177e7d3cf2f66d836f089f5e7ca6273db5b363a22686c2e35cb5201ebe7fe5af8e8ea80061586282cb76931f74dd138')

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
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-distro() {
  depends=('python2' 'python2-setuptools')
  cd distro-${pkgver}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  mv "${pkgdir}/usr/bin/distro"{,2}
}

# vim: ts=2 sw=2 et:
