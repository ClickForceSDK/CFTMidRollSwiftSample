//
//  ViewController.swift
//  CFTMidRollSwiftSample
//
//  Created by CF-NB on 2023/11/6.
//

import UIKit
import iMFADTV
import AVKit

var midroll: MFPreRollView?
let kContentURLString: String = "https://v.holmesmind.com/1151/video/output/s_f96434d0f311f12bdcf5145796985719.mp4"
var contentPlayerViewController = AVPlayerViewController.init()

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        setupContentPlayer()
        DispatchQueue.main.asyncAfter(deadline: .now() + 5) {
            self.setMidRoll()
        }
    }
    
    func setMidRoll(){
        midroll = MFPreRollView.init(midRollFrame: contentPlayerViewController)
        midroll?.setZoneID("18379", get: self)
        midroll?.delegate = self;
        midroll?.setPlayer()
    }
    
    func setupContentPlayer() {
        let contentURL = URL(string: kContentURLString);
        let player = AVPlayer(url: contentURL!);
        contentPlayerViewController = AVPlayerViewController()
        contentPlayerViewController.player = player
        contentPlayerViewController.view.frame = self.view.bounds
        
        // Attach content video player to view hierarchy.
        showContentPlayer()
    }
    
    func showContentPlayer() {
        self.addChild(contentPlayerViewController);
        contentPlayerViewController.view.frame = self.view.bounds;
        self.view.insertSubview(contentPlayerViewController.view, at: 0);
        contentPlayerViewController.didMove(toParent: self);
        contentPlayerViewController.player?.play()
    }
    
    func hideContentPlayer() {
        contentPlayerViewController.willMove(toParent: self);
        contentPlayerViewController.view.removeFromSuperview();
        contentPlayerViewController.removeFromParent()
        contentPlayerViewController.player?.pause()
    }
}

extension ViewController: MFPreRollDelegate {
    func readyPlayVideo() {
        print("MidRoll end, start you'r video.")
    }
    
    func onFailedToVast() {
        print("MidRoll fail.")
    }
}


