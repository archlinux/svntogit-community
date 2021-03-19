# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=samus
pkgname=ruby-${_gemname}
pkgver=3.0.9
pkgrel=2
pkgdesc='Helps you automate the release of Open Source Software'
url='https://github.com/lsegal/samus'
arch=('any')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rake' 'ruby-rdoc')
options=('!emptydirs')
source=(${url}/archive/v${pkgver}/${pkgname}-v${pkgver}.tar.gz)
sha512sums=('da03a00ce0ced8249a696c6b558499939316a84f8aede86829557c31aaec3621adaff3e969b1fec32fc3249ba2f244b1adca545a2f7c4a9b9fdae7629194191b')
b2sums=('049a9f8691d7df77ce4721d6ca306fccc26f167b0dba954a5e90a16dc7ce3baf92288583d3b601dfee8b6160c5b48541317b5a09e61a70612b6c63da7b2899fa')

prepare() {
  cd ${_gemname}-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec
  sed 's|git ls-files|find|' -i ${_gemname}.gemspec
}

build() {
  cd ${_gemname}-${pkgver}
  gem build ${_gemname}.gemspec
}

package() {
  cd ${_gemname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" \
    -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"

  cd "${pkgdir}/${_gemdir}"
  rm -rf cache gems/${_gemname}-${pkgver}/{ext,lib/*/*.so,man} \
    extensions/*/*/${_gemname}-${pkgver}/{mkmf.log,gem_make.out}
}

# vim: ts=2 sw=2 et:
