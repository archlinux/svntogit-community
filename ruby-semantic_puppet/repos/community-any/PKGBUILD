# Maintainer: Tim Meusel <tim@bastelfreak.de>
_gemname=semantic_puppet
pkgname="ruby-$_gemname"
pkgver=1.0.4
pkgrel=1
pkgdesc='Tools used by Puppet to parse, validate, and compare Semantic Versions and Version Ranges and to query and resolve module dependencies.'
arch=('any')
url='https://github.com/puppetlabs/semantic_puppet'
depends=('ruby')
makedepends=('ruby-rdoc' 'rubygems')
license=('Apache')
options=('!emptydirs')
source=("https://rubygems.org/gems/${_gemname}-${pkgver}.gem")
noextract=("${_gemname}-${pkgver}.gem")
sha512sums=('8b830626e973bc74fb4f4147e83ca8048d412751ff48dbe96ec6e790645eae7a51c665b75a09d0f0fdec3b29d3798158c38b613e2f83d115d1ba2a4c8d24362a')
package() {
  local _gemdir="$(ruby -e'puts Gem.default_dir')"

  gem install \
    --ignore-dependencies \
    --no-user-install \
    --install-dir "${pkgdir}${_gemdir}" \
    --bindir "${pkgdir}/usr/bin" \
    --verbose \
    ${_gemname}-${pkgver}.gem

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"

  install -D -m644 "${pkgdir}${_gemdir}/gems/semantic_puppet-${pkgver}/LICENSE" "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
